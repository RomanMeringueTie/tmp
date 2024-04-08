#include <myBigChars.h>

char *
bc_decode (char *utf8_string)
{
  int len = strlen ((const char *)utf8_string);
  int utf8_index = 0;

  // Allocate memory for the decoded string
  char *decoded_string = (char *)malloc (len + 1);
  if (!decoded_string)
    {
      return "\0";
    }

  int decoded_index = 0;
  while (utf8_string[utf8_index] != '\0')
    {
      unsigned char ch = utf8_string[utf8_index];

      if ((ch & 0x80) == 0)
        { // 1-byte character (ASCII)
          decoded_string[decoded_index++] = (char)ch;
          utf8_index++;
        }
      else if ((ch & 0xE0) == 0xC0)
        { // 2-byte character
          unsigned char byte1 = utf8_string[utf8_index++];
          unsigned char byte2 = utf8_string[utf8_index++];
          decoded_string[decoded_index++]
              = ((byte1 & 0x1F) << 6) | (byte2 & 0x3F);
        }
      else if ((ch & 0xF0) == 0xE0)
        { // 3-byte character
          unsigned char byte1 = utf8_string[utf8_index++];
          unsigned char byte2 = utf8_string[utf8_index++];
          unsigned char byte3 = utf8_string[utf8_index++];
          decoded_string[decoded_index++] = ((byte1 & 0x0F) << 12)
                                            | ((byte2 & 0x3F) << 6)
                                            | (byte3 & 0x3F);
        }
      else if ((ch & 0xF8) == 0xF0)
        { // 4-byte character
          unsigned char byte1 = utf8_string[utf8_index++];
          unsigned char byte2 = utf8_string[utf8_index++];
          unsigned char byte3 = utf8_string[utf8_index++];
          unsigned char byte4 = utf8_string[utf8_index++];
          decoded_string[decoded_index++]
              = ((byte1 & 0x07) << 18) | ((byte2 & 0x3F) << 12)
                | ((byte3 & 0x3F) << 6) | (byte4 & 0x3F);
        }
      else
        {
          // Invalid UTF-8 sequence
          // free(decoded_string);
          return "\0";
        }
    }

  decoded_string[decoded_index] = '\0'; // Null-terminate the decoded string
  return decoded_string;
}