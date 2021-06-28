/*
 * Copyright (c) 2021 krishpranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

// includes
#include <AK/Assertions.h>
#include <AK/Format.h>
#include <wchar.h>

extern "C" {

size_t wcslen(const wchar_t* str)
{
    size_t len = 0;
    while (*(str++))
        ++len;
    return len;
}

wchar_t* wcscpy(wchar_t* dest, const wchar_t* src)
{
    wchar_t* original_dest = dest;
    while ((*dest++ = *src++) != '\0')
        ;
    return original_dest;
}

wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t num)
{
    wchar_t* original_dest = dest;
    while (((*dest++ = *src++) != '\0') && ((size_t)(dest - original_dest) < num))
        ;
    return original_dest;
}

int wcscmp(const wchar_t* s1, const wchar_t* s2)
{
    while (*s1 == *s2++)
        if (*s1++ == 0)
            return 0;
    return *(const wchar_t*)s1 - *(const wchar_t*)--s2;
}


}