////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMaxSize1.hpp>
#include <ya/commands/spatial/AddMaxSize1.hpp>
#include <ya/commands/spatial/AddMaxSizeX.hpp>
#include <ya/commands/spatial/MultiplyMaxSize.hpp>
#include <ya/commands/spatial/MultiplyMaxSize1.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeX.hpp>
#include <ya/commands/spatial/SetMaxSize1.hpp>
#include <ya/commands/spatial/SetMaxSizeX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMaxSize¹>();
        w.property(UNSAFE, "max_size", &AMaxSize¹::m_max_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMaxSize¹::on_set_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_set_max_sizeX);

        w.slot(UNSAFE, &AMaxSize¹::on_add_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_add_max_sizeX);
        
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_sizeX);
    }
}
