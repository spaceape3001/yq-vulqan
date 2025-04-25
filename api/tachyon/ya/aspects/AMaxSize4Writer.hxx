////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMaxSize4.hpp>
#include <tachyon/command/size/AddMaxSize4.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/AddMaxSizeY.hpp>
#include <tachyon/command/size/AddMaxSizeZ.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize4.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSizeY.hpp>
#include <tachyon/command/size/MultiplyMaxSizeZ.hpp>
#include <tachyon/command/size/SetMaxSize4.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/command/size/SetMaxSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize⁴::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize⁴>();
        w.property(UNSAFE, "max_size", &AMaxSize⁴::m_max_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_size4);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeW);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeX);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeY);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeZ);

        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_size4);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeX);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeW);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeY);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeZ);
        
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_size4);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeW);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeX);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeY);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeZ);
    }
}
