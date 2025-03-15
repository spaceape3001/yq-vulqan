////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize4.hpp>
#include <ya/commands/size/AddSize4.hpp>
#include <ya/commands/size/AddSizeW.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/AddSizeY.hpp>
#include <ya/commands/size/AddSizeZ.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize4.hpp>
#include <ya/commands/size/MultiplySizeW.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/MultiplySizeY.hpp>
#include <ya/commands/size/MultiplySizeZ.hpp>
#include <ya/commands/size/SetSize4.hpp>
#include <ya/commands/size/SetSizeW.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <ya/commands/size/SetSizeY.hpp>
#include <ya/commands/size/SetSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize⁴::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ISize⁴>();
        w.property(UNSAFE, "size", &ASize⁴::m_size).tag(kTag_Save);

        w.slot(UNSAFE, &ASize⁴::on_set_size4);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeW);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeX);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeY);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeZ);

        w.slot(UNSAFE, &ASize⁴::on_add_size4);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeW);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeX);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeY);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeZ);
        
        w.slot(UNSAFE, &ASize⁴::on_multiply_size);
        w.slot(UNSAFE, &ASize⁴::on_multiply_size4);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeW);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeY);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeZ);
    }
}
