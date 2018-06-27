/*
 * MRustC - Rust Compiler
 * - By John Hodge (Mutabah/thePowersGang)
 *
 * common/target_detect.h
 * - Auto-magical host target detection
 */
#pragma once

// - Windows (MSVC)
#ifdef _MSC_VER
# if defined(_WIN64)
#  define DEFAULT_TARGET_NAME "x86_64-windows-msvc"
# else
#  define DEFAULT_TARGET_NAME "x86-windows-msvc"
# endif
// - Linux
#elif defined(__linux__)
# if defined(__amd64__)
#  define DEFAULT_TARGET_NAME "x86_64-linux-gnu"
# elif defined(__aarch64__)
#  define DEFAULT_TARGET_NAME "aarch64-linux-gnu"
# elif defined(__arm__)
#  define DEFAULT_TARGET_NAME "arm-linux-gnu"
# elif defined(__i386__)
#  define DEFAULT_TARGET_NAME "i586-linux-gnu"
# else
#  warning "Unable to detect a suitable default target (linux-gnu)"
# endif
// - MinGW
#elif defined(__MINGW32__)
# if defined(_WIN64)
#  define DEFAULT_TARGET_NAME "x86_64-windows-gnu"
# else
#  define DEFAULT_TARGET_NAME "i586-windows-gnu"
# endif
// - FreeBSD
#elif defined(__FreeBSD__)
# if defined(__amd64__)
#  define DEFAULT_TARGET_NAME "x86_64-unknown-freebsd"
# elif defined(__aarch64__)
#  define DEFAULT_TARGET_NAME "aarch64-unknown-freebsd"
# elif defined(__arm__)
#  define DEFAULT_TARGET_NAME "arm-unknown-freebsd"
# elif defined(__i386__)
#  define DEFAULT_TARGET_NAME "i686-unknown-freebsd"
# else
#  warning "Unable to detect a suitable default target (FreeBSD)"
# endif
// - NetBSD
#elif defined(__NetBSD__)
# if defined(__amd64__)
#  define DEFAULT_TARGET_NAME "x86_64-unknown-netbsd"
# else
#  warning "Unable to detect a suitable default target (NetBSD)"
# endif
// - OpenBSD
#elif defined(__OpenBSD__)
# if defined(__amd64__)
#  define DEFAULT_TARGET_NAME "x86_64-unknown-openbsd"
# elif defined(__aarch64__)
#  define DEFAULT_TARGET_NAME "aarch64-unknown-openbsd"
# elif defined(__arm__)
#  define DEFAULT_TARGET_NAME "arm-unknown-openbsd"
# elif defined(__i386__)
#  define DEFAULT_TARGET_NAME "i686-unknown-openbsd"
# else
#  warning "Unable to detect a suitable default target (OpenBSD)"
# endif
// - DragonFly
#elif defined(__DragonFly__)
# define DEFAULT_TARGET_NAME "x86_64-unknown-dragonfly"
// - Apple devices
#elif defined(__APPLE__)
# define DEFAULT_TARGET_NAME "x86_64-apple-macosx"
// - Unknown
#else
# warning "Unable to detect a suitable default target"
#endif
#ifndef DEFAULT_TARGET_NAME
# define DEFAULT_TARGET_NAME	""
#endif
