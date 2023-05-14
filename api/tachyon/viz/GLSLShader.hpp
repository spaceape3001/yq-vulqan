////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <tachyon/enum/ShaderType.hpp>
#include <basic/preamble.hpp>
#include <basic/ByteArray.hpp>
#include <filesystem>
#include <variant>

namespace yq::tachyon::glsl {

    const std::filesystem::path&            compiler();
    const std::filesystem::path&            validator();
    
    using Source    = std::variant<ByteArray, std::filesystem::path>;

    std::pair<ByteArray,std::error_code>    compile(const Source&);
    std::pair<ByteArray,std::error_code>    validate(const Source&, ShaderType st=ShaderType());
    
    ShaderType                              shader_type(const std::filesystem::path&);
    
}
