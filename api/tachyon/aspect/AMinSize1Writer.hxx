////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMinSize1.hpp>
#include <tachyon/command/size/AddMinSize1.hpp>
#include <tachyon/command/size/AddMinSizeX.hpp>
#include <tachyon/command/size/MultiplyMinSize.hpp>
#include <tachyon/command/size/MultiplyMinSize1.hpp>
#include <tachyon/command/size/MultiplyMinSizeX.hpp>
#include <tachyon/command/size/SetMinSize1.hpp>
#include <tachyon/command/size/SetMinSizeX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize¹>();
        w.property(UNSAFE, "min_size", &AMinSize¹::m_min_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMinSize¹::on_set_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_set_min_sizeX);

        w.slot(UNSAFE, &AMinSize¹::on_add_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_add_min_sizeX);
        
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_sizeX);
    }
}
