/*
 * Copyright (c) 2021 nuke123-sudo
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

// includes
#include <arpa/inet.h>
#include <errno.h>
#include <serenity.h>
#include <string.h>
#include <syscall.h>


extern "C" {

int disown(pid_t pid)
{
    int rc = syscall(SC_disown, pid);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int module_load(const char* path, size_t path_length)
{
    int rc = syscall(SC_module_load, path, path_length);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int module_unload(const char* name, size_t name_length)
{
    int rc = syscall(SC_module_unload, name, name_length);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int profiling_enable(pid_t pid, uint64_t event_mask)
{
    int rc = syscall(SC_profiling_enable, pid, event_mask);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int profiling_disable(pid_t pid)
{
    int rc = syscall(SC_profiling_disable, pid);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int profiling_free_buffer(pid_t pid)
{
    int rc = syscall(SC_profiling_free_buffer, pid);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int futex(uint32_t* userspace_address, int futex_op, uint32_t value, const struct timespec* timeout, uint32_t* userspace_address2, uint32_t value3)
{
    int rc;
    switch (futex_op & FUTEX_CMD_MASK) {
    case FUTEX_WAKE_OP: {
        Syscall::SC_futex_params params {
            .userspace_address = userspace_address,
            .futex_op = futex_op,
            .val = value,
            .val2 = (FlatPtr)timeout,
            .userspace_address2 = userspace_address2,
            .val3 = value3
        };
        rc = syscall(SC_futex, &params);
        break;
    }
    default: {
        Syscall::SC_futex_params params {
            .userspace_address = userspace_address,
            .futex_op = futex_op,
            .val = value,
            .timeout = timeout,
            .userspace_address2 = userspace_address2,
            .val3 = value3
        };
        rc = syscall(SC_futex, &params);
        break;
    }
    }
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int purge(int mode)
{
    int rc = syscall(SC_purge, mode);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}

int perf_event(int type, uintptr_t arg1, FlatPtr arg2)
{
    int rc = syscall(SC_perf_event, type, arg1, arg2);
    __RETURN_WITH_ERRNO(rc, rc, -1);
}


}