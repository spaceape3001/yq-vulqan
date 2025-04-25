////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMinSize4.hpp>
#include <tachyon/command/size/AddMinSize4.hpp>
#include <tachyon/command/size/AddMinSizeW.hpp>
#include <tachyon/command/size/AddMinSizeX.hpp>
#include <tachyon/command/size/AddMinSizeY.hpp>
#include <tachyon/command/size/AddMinSizeZ.hpp>
#include <tachyon/command/size/MultiplyMinSize.hpp>
#include <tachyon/command/size/MultiplyMinSize4.hpp>
#include <tachyon/command/size/MultiplyMinSizeW.hpp>
#include <tachyon/command/size/MultiplyMinSizeX.hpp>
#include <tachyon/command/size/MultiplyMinSizeY.hpp>
#include <tachyon/command/size/MultiplyMinSizeZ.hpp>
#include <tachyon/command/size/SetMinSize4.hpp>
#include <tachyon/command/size/SetMinSizeW.hpp>
#include <tachyon/command/size/SetMinSizeX.hpp>
#include <tachyon/command/size/SetMinSizeY.hpp>
#include <tachyon/command/size/SetMinSizeZ.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize⁴::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize⁴>();
        w.property(UNSAFE, "min_size", &AMinSize⁴::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize⁴::on_set_min_size4);
        w.slot(UNSAFE, &AMinSize⁴::on_set_min_sizeW);
        w.slot(UNSAFE, &AMinSize⁴::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize⁴::on_set_min_sizeY);
        w.slot(UNSAFE, &AMinSize⁴::on_set_min_sizeZ);

        w.slot(UNSAFE, &AMinSize⁴::on_add_min_size4);
        w.slot(UNSAFE, &AMinSize⁴::on_add_min_sizeW);
        w.slot(UNSAFE, &AMinSize⁴::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize⁴::on_add_min_sizeY);
        w.slot(UNSAFE, &AMinSize⁴::on_add_min_sizeZ);
        
        w.slot(UNSAFE, &AMinSize⁴::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize⁴::on_multiply_min_size4);
        w.slot(UNSAFE, &AMinSize⁴::on_multiply_min_sizeW);
        w.slot(UNSAFE, &AMinSize⁴::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize⁴::on_multiply_min_sizeY);
        w.slot(UNSAFE, &AMinSize⁴::on_multiply_min_sizeZ);
    }
}
