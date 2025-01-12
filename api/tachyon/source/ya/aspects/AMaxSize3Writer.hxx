////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMaxSize3.hpp>
#include <ya/commands/spatial/AddMaxSize3.hpp>
#include <ya/commands/spatial/AddMaxSizeX.hpp>
#include <ya/commands/spatial/AddMaxSizeY.hpp>
#include <ya/commands/spatial/AddMaxSizeZ.hpp>
#include <ya/commands/spatial/MultiplyMaxSize.hpp>
#include <ya/commands/spatial/MultiplyMaxSize3.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeX.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeY.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeZ.hpp>
#include <ya/commands/spatial/SetMaxSize3.hpp>
#include <ya/commands/spatial/SetMaxSizeX.hpp>
#include <ya/commands/spatial/SetMaxSizeY.hpp>
#include <ya/commands/spatial/SetMaxSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize³>();
        w.property(UNSAFE, "max_size", &AMaxSize³::m_max_size);

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
