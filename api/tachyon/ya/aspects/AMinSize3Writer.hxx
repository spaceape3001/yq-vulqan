////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMinSize3.hpp>
#include <ya/commands/spatial/AddMinSize3.hpp>
#include <ya/commands/spatial/AddMinSizeX.hpp>
#include <ya/commands/spatial/AddMinSizeY.hpp>
#include <ya/commands/spatial/AddMinSizeZ.hpp>
#include <ya/commands/spatial/MultiplyMinSize.hpp>
#include <ya/commands/spatial/MultiplyMinSize3.hpp>
#include <ya/commands/spatial/MultiplyMinSizeX.hpp>
#include <ya/commands/spatial/MultiplyMinSizeY.hpp>
#include <ya/commands/spatial/MultiplyMinSizeZ.hpp>
#include <ya/commands/spatial/SetMinSize3.hpp>
#include <ya/commands/spatial/SetMinSizeX.hpp>
#include <ya/commands/spatial/SetMinSizeY.hpp>
#include <ya/commands/spatial/SetMinSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize³>();
        w.property(UNSAFE, "min_size", &AMinSize³::m_min_size);

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
