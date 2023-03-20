#ifndef LAB3_ALGORITHMS_H
#define LAB3_ALGORITHMS_H

namespace en {
    template<typename Iterator, typename Predicate>
    bool all_of(Iterator begin, Iterator end, Predicate pred) {
        for (; begin != end; ++begin)
            if (!pred(*begin)) {
                return false;
            }
        return true;
    }

    template<typename Iterator, typename Predicate>
    bool any_of(Iterator begin, Iterator end, Predicate pred) {
        for (; begin != end; begin++)
            if (pred(*begin))
                return true;
        return false;
    }

    template<typename Iterator, typename Predicate>
    bool none_of(Iterator begin, Iterator end, Predicate pred) {
        for (; begin != end; begin++)
            if (pred(*begin))
                return false;
        return true;
    }

    template<typename Iterator, typename Predicate>
    bool one_of(Iterator begin, Iterator end, Predicate pred) {
        size_t count = 0;
        for (; begin != end; begin++)
            if (pred(*begin))
                ++count;
        return count == 1;
    }

    template<typename Iterator, typename Comparator>
    bool is_sorted(Iterator begin, Iterator end, Comparator comp) {
        if (begin == end) return true;
        Iterator second = begin;
        while (++second != end) {
            if (!comp(*begin, *second))
                return false;
            begin = second;
        }
        return true;
    }

    template<typename Iterator, typename Predicate>
    bool partitioned(Iterator begin, Iterator end, Predicate pred) {
        for (; begin != end; ++begin)
            if (!pred(*begin))
                break;
        if (begin == end)
            return true;
        ++begin;
        for (; begin != end; ++begin)
            if (pred(*begin))
                return false;
        return true;
    }

    template<typename Iterator, typename T>
    Iterator find_not(Iterator begin, Iterator end, T value) {
        for (; begin != end; ++begin)
            if (*begin != value)
                break;
        return begin;
    }

    template<typename Iterator, typename T>
    Iterator find_backward(Iterator begin, Iterator end, T value) {
        auto temp = end;
        --end;
        for (; end != begin; --end) {
            if (*end == value) {
                return end;
            }
        }

        if (*begin == value) {
            return begin;
        }
        else {
            return temp;
        }

    }

    template<typename Iterator, typename Comparator>
    bool is_palindrome(Iterator begin, Iterator end, Comparator comp) {
        auto j = end;
        --j;
        for (auto i = begin; i != end; ++i, --j) {
            if (comp(*i) != comp(*j)) {
                return false;
            }
        }
        return true;
    }
}
#endif //LAB3_ALGORITHMS_H
