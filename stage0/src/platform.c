#include "platform.h"

char* get_platform() {
    if (PLATFORM_MSNT) {
        return "MSNT";
    } else if (PLATFORM_LINUX) {
        return "Linux";
    } else if (PLATFORM_DARWIN) {
        return "Darwin";
    } else {
        return "Unknown";
    }
}

char* get_architecture() {
    if (ARCH_X86_64) {
        return "x86_64";
    } else if (ARCH_X86) {
        return "x86";
    } else if (ARCH_ARM64) {
        return "ARM64";
    } else if (ARCH_ARM) {
        return "ARM";
    } else {
        return "Unknown";
    }
}

system_info_t get_system_info() {
    system_info_t info;

    // Detect platform
    if (PLATFORM_MSNT) {
        info.platform = PLATFORM_MSNT;
    } else if (PLATFORM_LINUX) {
        info.platform = PLATFORM_LINUX;
    } else if (PLATFORM_DARWIN) {
        info.platform = PLATFORM_DARWIN;
    } else {
        info.platform = PLATFORM_UNKNOWN;
    }
    // Detect architecture
    if (ARCH_X86_64) {
        info.architecture = ARCH_X86_64;
    } else if (ARCH_X86) {
        info.architecture = ARCH_X86;
    } else if (ARCH_ARM64) {
        info.architecture = ARCH_ARM64;
    } else if (ARCH_ARM) {
        info.architecture = ARCH_ARM;
    } else {
        info.architecture = ARCH_UNKNOWN;
    }
    return info;
}