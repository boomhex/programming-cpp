#include <string>
#include <vector>

class Words
{
    std::vector<std::string> d_words;

    public: 
        void add(std::string const &w);
        size_t size() const;
        size_t capacity() const;
        void swap(Words &other);
};

inline void Words::add(std::string const &w)
{
    d_words.push_back(w);
}

inline size_t Words::size() const
{
    return d_words.size();
}

inline size_t Words::capacity() const
{
    return d_words.capacity();
}

inline void Words::swap(Words &other)
{
    d_words.swap(other.d_words);
}