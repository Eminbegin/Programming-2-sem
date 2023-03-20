#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP
#include <utility>
#include <vector>
#include <cstddef>
#include <cmath>
#include <memory>
#include <map>
#include "algorithm"
template <typename T>
class Allocator {
public:
    using value_type = T;
    using pointer = T*;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;

    template <class U>
    friend class Allocator;

    template<class Z>
    struct rebind {
        using other = Allocator<Z>;
    };
    bool operator!=(const Allocator<T> &other) const {
        return other.pool == pool;
    };
    bool operator==(const Allocator<T> &other) const {
        return !(*this == other);
    };
    Allocator(std::map<int, int>::const_iterator mbegin, std::map<int, int>::const_iterator mend) {
        for (; mbegin != mend; ++mbegin) {
            size_type k = mbegin->second;                                                   //количсетво блоков
            size_type n = mbegin->first;                                                    //количество элементов в блоке
            size_type remainsSize = k * n;                                                  //весь размер
            pool[n] = Chunk(n, k, std::shared_ptr<T>(new T[k*n]));                          //выделил память
            pool[n].setFirstBlock(pool[n].blockk);                                          //ссылка на первую
            remainsSize -= n;                                                               //сдвиг
            Block* prevBlock = new(pool[n].blockk.get() + remainsSize) Block();             //создаем первый, указвыающий на нул
            for (int i = k - 2; i >= 0; --i) {
                remainsSize -= n;                                                           //свдиг
                Block* curBlock = new(pool[n].blockk.get() + remainsSize) Block(prevBlock); //создание следующего
                curBlock->next = prevBlock;                                                 // заполняем некст у кур
                prevBlock = curBlock;                                                       //делаем кур полседним созданным
            }
        }
    };
    ~Allocator() = default;

    template<typename U>
    Allocator(const Allocator<U>& other) {
        pool = other.pool;
    }

    pointer allocate(size_type n) {
        size_type t = -1;
        for (auto iter:pool) {
            if (iter.first >= n && iter.second.getFirstBlock() != nullptr) {
                t = iter.first;
                break;
            }
        }
        if (t == -1) {
            throw std::bad_alloc();
        }
        Block* res = pool[t].getFirstBlock();
        pool[t].setFirstBlock(res->next);
        return reinterpret_cast<T*>(res);

    }
    void deallocate(pointer p, size_type n) {
        bool flag = false;
        for (auto iter: pool) {
            if (iter.second.isHere(p)) {
                flag = true;
                Block* tempBlock = new(p) Block(iter.second.getFirstBlock());
                iter.second.setFirstBlock(tempBlock);
//                new(p) Block(iter.second.getFirstBlock());
//                iter.second.setFirstBlock(p);
                break;
            }
        }
    }
private:
    struct Block {
        Block* next = nullptr;
        explicit Block(Block* next_) {next = next_;}
        explicit Block() = default;
    };
    struct Chunk { // сeттеры и геттеры хуита
    private:
        Block* firstBlock = nullptr;
    public:
        template<typename S>
        void setFirstBlock(S* a) {
            firstBlock = reinterpret_cast<Block*>(a);
        }
        template<typename S>
        void setFirstBlock(std::shared_ptr<S> a) {
            setFirstBlock(a.get());
        }
        Block* getFirstBlock() const {
            return firstBlock;
        }
        bool isHere(pointer p) {
            auto diff = p - blockk.get();
            if (diff == cellSize * cellCount) {
                throw std::logic_error("We're trying to free border memory");
            }
            return diff >= 0 && diff < cellSize * cellCount;
        }
        size_t cellSize = 0;
        size_t cellCount = 0;
        std::shared_ptr<T> blockk = nullptr;
        explicit Chunk(size_t cellSize_, size_t cellCount_, std::shared_ptr<T> blockk_) {
            cellSize = cellSize_;
            cellCount = cellCount_;
            blockk = std::move(blockk_);
        }
        explicit Chunk() = default;
        bool operator== (const Chunk& other) const{
            return blockk == other.blockk;
        }
        bool operator!= (const Chunk& other) const{
            return !(this == other);
        }
    };
    std::map<size_t, Chunk> pool;
};

#endif
