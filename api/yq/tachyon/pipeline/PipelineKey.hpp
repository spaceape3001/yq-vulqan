////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <cstdint>
#include <compare>
#include <functional>

namespace yq::tachyon {

    //! A way to keep track of pipelines in rendered's meta... with conventions
    struct PipelineKey {
        uint16_t    id = 0;
        
        constexpr PipelineKey() noexcept = default;
        constexpr PipelineKey(uint16_t v) noexcept : id(v) {}
        constexpr auto operator<=>(const PipelineKey&) const noexcept = default;
        constexpr operator uint16_t() const noexcept { return id; }
    };

    namespace pipekey {
        static constexpr const PipelineKey  INVALID             = 0xFFFF;
        static constexpr const PipelineKey  DEFAULT             = 0x0000;
        
        // after this, exact numbers are unimportant other than to be unique
        
        static constexpr const PipelineKey  DEBUG               = 0x0001;
        
        static constexpr const PipelineKey  DBG_BLACK           = 0x0002;
        static constexpr const PipelineKey  DBG_RED             = 0x0003;
        static constexpr const PipelineKey  DBG_ORANGE          = 0x0004;
        static constexpr const PipelineKey  DBG_YELLOW          = 0x0005;
        static constexpr const PipelineKey  DBG_GREEN           = 0x0006;
        static constexpr const PipelineKey  DBG_BLUE            = 0x0007;
        static constexpr const PipelineKey  DBG_CYAN            = 0x0008;
        static constexpr const PipelineKey  DBG_MAGENTA         = 0x0009;
        static constexpr const PipelineKey  DBG_GRAY            = 0x000A;
        static constexpr const PipelineKey  DBG_WHITE           = 0x000B;
        
        // some more diagnostics...

        //! "Simple" pipeline
        static constexpr const PipelineKey  SIMPLE              = 0x0010;

        //! "Simple" pipeline with lighting
        static constexpr const PipelineKey  SIMPLE_LIT          = 0x0011;

        //! "Simple" pipeline with ray tracing
        static constexpr const PipelineKey  SIMPLE_RAY          = 0x0012;
        
        //! Solid color 
        static constexpr const PipelineKey  SOLID_COLOR         = 0x0020;

        //! Solid color with simple lighting
        static constexpr const PipelineKey  SOLID_COLOR_LIT     = 0x0021;

        //! Solid color with ray tracing
        static constexpr const PipelineKey  SOLID_COLOR_RAY     = 0x0022;

        //! "Gradient" pipeline
        static constexpr const PipelineKey  GRADIENT            = 0x0030;

        //! "Gradient" pipeline with lighting
        static constexpr const PipelineKey  GRADIENT_LIT        = 0x0031;

        //! "Gradient" pipeline with ray tracing
        static constexpr const PipelineKey  GRADIENT_RAY        = 0x0032;

        //! Corners define colors, gradients in between
        static constexpr const PipelineKey  CORNER_COLOR        = 0x0040;
        
        //! Corners define colors with simple lighting
        static constexpr const PipelineKey  CORNER_COLOR_LIT    = 0x0041;
        
        //! Corners define colors with ray tracing
        static constexpr const PipelineKey  CORNER_COLOR_RAY    = 0x0042;

        //! Regular textures
        static constexpr const PipelineKey  TEXTURED            = 0x0050;

        //! Regular textures with simple lighting
        static constexpr const PipelineKey  TEXTURED_LIT        = 0x0051;

        //! Regular textures with ray tracing
        static constexpr const PipelineKey  TEXTURED_RAY        = 0x0052;

        //! Materials
        static constexpr const PipelineKey  MATERIAL            = 0x0060;

        //! Materials with simple lighting
        static constexpr const PipelineKey  MATERIAL_LIT        = 0x0061;

        //! Materials with ray tracing
        static constexpr const PipelineKey  MATERIAL_RAY        = 0x0062;

        //! User defined keys after this...
        static constexpr const PipelineKey  USER                = 0x0400;
    };
}

template <>
struct std::hash<yq::tachyon::PipelineKey> : public std::hash<uint16_t> {};
