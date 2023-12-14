#include <UraniumGlobals.h>

namespace Uranium
{
    // Definitions in one source file
    FormatVersion GlobalFormatVersion = FormatVersion(1, 20, 50);
    FormatVersion GlobalBlockFormatVersion = GlobalFormatVersion;
    std::string GlobalProjectNamespace = "";
    UUIDv4::UUIDGenerator<std::mt19937_64> GlobalUUIDGenerator;

    void SetGlobalProjectNamespace(const std::string& newValue) {
        GlobalProjectNamespace = newValue;
    }
} // namespace Uranium