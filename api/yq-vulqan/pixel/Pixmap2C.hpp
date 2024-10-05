////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/pixmap/Pixmap2.hpp>
#include <yq-toolbox/container/Array.hpp>

namespace yq::tachyon {
    template <typename C>
    class Pixmap2C : public Pixmap2 {
        YQ_OBJECT_DECLARE(Pixmap2C, Pixmap2)
    public:
    
        virtual ImageCPtr   to_image(const ImageConfig& config={}) const override;
    };
}
