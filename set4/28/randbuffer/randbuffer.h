#ifndef INCLUDED_RANDBUFFER_
#define INCLUDED_RANDBUFFER_

#include <streambuf>

class RandBuffer : public std::streambuf
{
  int d_min;
  size_t d_range;
  size_t d_end;
  char *d_buffer;

  using traits_type = std::streambuf::traits_type;

public:
  using int_type = traits_type::int_type;

  RandBuffer(int min, int max, size_t seed);
  ~RandBuffer();

protected:
  int_type underflow() override;
};

#endif
