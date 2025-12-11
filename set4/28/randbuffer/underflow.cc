#include "randbuffer.ih"

RandBuffer::int_type RandBuffer::underflow()
{
  if (gptr() != egptr()) // buffer still has chars
    return traits_type::to_int_type(*gptr());

  size_t value = 0;

  while (true)
  {
    value = static_cast<size_t>(random());

    if (value < d_end)
      break;
  }

  int const next = d_min + static_cast<int>(value % d_range);

  string const text = to_string(next);
  size_t const length = text.length();

  delete[] d_buffer;
  d_buffer = new char[length];

  text.copy(d_buffer, length);

  setg(d_buffer, d_buffer, d_buffer + length);

  return traits_type::to_int_type(*gptr());
}
