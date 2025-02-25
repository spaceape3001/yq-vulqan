////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMaxSize3.hpp>
#include <ya/commands/size/AddMaxSize3.hpp>
#include <ya/commands/size/AddMaxSizeX.hpp>
#include <ya/commands/size/AddMaxSizeY.hpp>
#include <ya/commands/size/AddMaxSizeZ.hpp>
#include <ya/commands/size/MultiplyMaxSize.hpp>
#include <ya/commands/size/MultiplyMaxSize3.hpp>
#include <ya/commands/size/MultiplyMaxSizeX.hpp>
#include <ya/commands/size/MultiplyMaxSizeY.hpp>
#include <ya/commands/size/MultiplyMaxSizeZ.hpp>
#include <ya/commands/size/SetMaxSize3.hpp>
#include <ya/commands/size/SetMaxSizeX.hpp>
#include <ya/commands/size/SetMaxSizeY.hpp>
#include <ya/commands/size/SetMaxSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize³>();
        w.property(UNSAFE, "max_size", &AMaxSize³::m_max_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMaxSize³::on_set_max_size3);
        w.slot(UNSAFE, &AMaxSize³::on_set_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³::on_set_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³::on_set_max_sizeZ);

        w.slot(UNSAFE, &AMaxSize³::on_add_max_size3);
        w.slot(UNSAFE, &AMaxSize³::on_add_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³::on_add_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³::on_add_max_sizeZ);
        
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_size3);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_sizeZ);
    }
}
