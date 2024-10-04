#ifndef FILE
#define FILE

#include <filesystem>

// uses linux symbolic link to find exe, then finds parent directory,
// and builds executable there.
inline std::filesystem::path exe{std::filesystem::read_symlink("/proc/self/exe")};
inline std::filesystem::path dir{exe.parent_path()};

#endif