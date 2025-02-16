////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMaxSize2.hpp>
#include <ya/commands/spatial/AddMaxSize2.hpp>
#include <ya/commands/spatial/AddMaxSizeX.hpp>
#include <ya/commands/spatial/AddMaxSizeY.hpp>
#include <ya/commands/spatial/MultiplyMaxSize.hpp>
#include <ya/commands/spatial/MultiplyMaxSize2.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeX.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeY.hpp>
#include <ya/commands/spatial/SetMaxSize2.hpp>
#include <ya/commands/spatial/SetMaxSizeX.hpp>
#include <ya/commands/spatial/SetMaxSizeY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMaxSize²>();
        w.property(UNSAFE, "max_size", &AMaxSize²::m_max_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMaxSize²::on_set_max_size2);
        w.slot(UNSAFE, &AMaxSize²::on_set_max_sizeX);
        w.slot(UNSAFE, &AMaxSize²::on_set_max_sizeY);

        w.slot(UNSAFE, &AMaxSize²::on_add_max_size2);
        w.slot(UNSAFE, &AMaxSize²::on_add_max_sizeX);
        w.slot(UNSAFE, &AMaxSize²::on_add_max_sizeY);
        
        w.slot(UNSAFE, &AMaxSize²::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize²::on_multiply_max_size2);
        w.slot(UNSAFE, &AMaxSize²::on_multiply_max_sizeX);
        w.slot(UNSAFE, &AMaxSize²::on_multiply_max_sizeY);
    }
}
