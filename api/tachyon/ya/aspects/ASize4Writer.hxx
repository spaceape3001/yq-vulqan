////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize4.hpp>
#include <tachyon/command/size/AddSize4.hpp>
#include <tachyon/command/size/AddSizeW.hpp>
#include <tachyon/command/size/AddSizeX.hpp>
#include <tachyon/command/size/AddSizeY.hpp>
#include <tachyon/command/size/AddSizeZ.hpp>
#include <tachyon/command/size/MultiplySize.hpp>
#include <tachyon/command/size/MultiplySize4.hpp>
#include <tachyon/command/size/MultiplySizeW.hpp>
#include <tachyon/command/size/MultiplySizeX.hpp>
#include <tachyon/command/size/MultiplySizeY.hpp>
#include <tachyon/command/size/MultiplySizeZ.hpp>
#include <tachyon/command/size/SetSize4.hpp>
#include <tachyon/command/size/SetSizeW.hpp>
#include <tachyon/command/size/SetSizeX.hpp>
#include <tachyon/command/size/SetSizeY.hpp>
#include <tachyon/command/size/SetSizeZ.hpp>
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
