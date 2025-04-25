////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMinSize3.hpp>
#include <tachyon/command/size/AddMinSize3.hpp>
#include <tachyon/command/size/AddMinSizeX.hpp>
#include <tachyon/command/size/AddMinSizeY.hpp>
#include <tachyon/command/size/AddMinSizeZ.hpp>
#include <tachyon/command/size/MultiplyMinSize.hpp>
#include <tachyon/command/size/MultiplyMinSize3.hpp>
#include <tachyon/command/size/MultiplyMinSizeX.hpp>
#include <tachyon/command/size/MultiplyMinSizeY.hpp>
#include <tachyon/command/size/MultiplyMinSizeZ.hpp>
#include <tachyon/command/size/SetMinSize3.hpp>
#include <tachyon/command/size/SetMinSizeX.hpp>
#include <tachyon/command/size/SetMinSizeY.hpp>
#include <tachyon/command/size/SetMinSizeZ.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize³>();
        w.property(UNSAFE, "min_size", &AMinSize³::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize³::on_set_min_size3);
        w.slot(UNSAFE, &AMinSize³::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize³::on_set_min_sizeY);
        w.slot(UNSAFE, &AMinSize³::on_set_min_sizeZ);

        w.slot(UNSAFE, &AMinSize³::on_add_min_size3);
        w.slot(UNSAFE, &AMinSize³::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize³::on_add_min_sizeY);
        w.slot(UNSAFE, &AMinSize³::on_add_min_sizeZ);
        
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_size3);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_sizeY);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_sizeZ);
    }
}
