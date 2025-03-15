////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMinSize4.hpp>
#include <ya/commands/size/AddMinSize4.hpp>
#include <ya/commands/size/AddMinSizeW.hpp>
#include <ya/commands/size/AddMinSizeX.hpp>
#include <ya/commands/size/AddMinSizeY.hpp>
#include <ya/commands/size/AddMinSizeZ.hpp>
#include <ya/commands/size/MultiplyMinSize.hpp>
#include <ya/commands/size/MultiplyMinSize4.hpp>
#include <ya/commands/size/MultiplyMinSizeW.hpp>
#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <ya/commands/size/MultiplyMinSizeY.hpp>
#include <ya/commands/size/MultiplyMinSizeZ.hpp>
#include <ya/commands/size/SetMinSize4.hpp>
#include <ya/commands/size/SetMinSizeW.hpp>
#include <ya/commands/size/SetMinSizeX.hpp>
#include <ya/commands/size/SetMinSizeY.hpp>
#include <ya/commands/size/SetMinSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

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
