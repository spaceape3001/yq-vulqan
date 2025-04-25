////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMinSize2.hpp>
#include <tachyon/command/size/AddMinSize2.hpp>
#include <tachyon/command/size/AddMinSizeX.hpp>
#include <tachyon/command/size/AddMinSizeY.hpp>
#include <tachyon/command/size/MultiplyMinSize.hpp>
#include <tachyon/command/size/MultiplyMinSize2.hpp>
#include <tachyon/command/size/MultiplyMinSizeX.hpp>
#include <tachyon/command/size/MultiplyMinSizeY.hpp>
#include <tachyon/command/size/SetMinSize2.hpp>
#include <tachyon/command/size/SetMinSizeX.hpp>
#include <tachyon/command/size/SetMinSizeY.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize²>();
        w.property(UNSAFE, "min_size", &AMinSize²::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize²::on_set_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_set_min_sizeY);

        w.slot(UNSAFE, &AMinSize²::on_add_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_add_min_sizeY);
        
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_sizeY);
    }
}
