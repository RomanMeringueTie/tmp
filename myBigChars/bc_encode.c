#include <myBigChars.h>

char *
bc_encode (char *input)
{
  int len = strlen (input);
  int utf8_size = len * 4 + 1; // Maximum UTF-8 size for each char

  unsigned char *utf8_string = (unsigned char *)malloc (utf8_size);

  if (!utf8_string)
    {
      return "\0";
    }

  int i, j = 0;
  for (i = 0; i < len; i++)
    {
      unsigned char ch = input[i];
      if (ch <= 0x7F)
        {
          utf8_string[j++] = ch;
        }
      else if (ch <= 0x7FF)
        {
          utf8_string[j++] = (ch >> 6) | 0xC0;
          utf8_string[j++] = (ch & 0x3F) | 0x80;
        }
      else if (ch <= 0xFFFF)
        {
          utf8_string[j++] = (ch >> 12) | 0xE0;
          utf8_string[j++] = ((ch >> 6) & 0x3F) | 0x80;
          utf8_string[j++] = (ch & 0x3F) | 0x80;
        }
      else
        {
          utf8_string[j++] = (ch >> 18) | 0xF0;
          utf8_string[j++] = ((ch >> 12) & 0x3F) | 0x80;
          utf8_string[j++] = ((ch >> 6) & 0x3F) | 0x80;
          utf8_string[j++] = (ch & 0x3F) | 0x80;
        }
    }

  utf8_string[j] = '\0'; // Null-terminate the string
  return utf8_string;
}