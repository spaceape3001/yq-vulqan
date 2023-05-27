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


    //! Path to the GLSL compiler
    const std::filesystem::path&            compiler();
    
    //! Path to the GLSL validator
    const std::filesystem::path&            validator();
    
    //! Source specifier for compilation/validation
    using Source    = std::variant<ByteArray, std::filesystem::path>;

    //! Compiles the given source using the GLSL compiler
    std::pair<ByteArray,std::error_code>    compile(const Source&);

    //! Validates the given source using the GLSL validator
    std::pair<ByteArray,std::error_code>    validate(const Source&, ShaderType st=ShaderType());
    
    //! Deduces shader type from given path's file extension
    ShaderType                              shader_type(const std::filesystem::path&);
    
}