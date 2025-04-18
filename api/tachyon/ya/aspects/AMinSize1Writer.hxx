////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMinSize1.hpp>
#include <ya/commands/size/AddMinSize1.hpp>
#include <ya/commands/size/AddMinSizeX.hpp>
#include <ya/commands/size/MultiplyMinSize.hpp>
#include <ya/commands/size/MultiplyMinSize1.hpp>
#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <ya/commands/size/SetMinSize1.hpp>
#include <ya/commands/size/SetMinSizeX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize¹>();
        w.property(UNSAFE, "min_size", &AMinSize¹::m_min_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMinSize¹::on_set_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_set_min_sizeX);

        w.slot(UNSAFE, &AMinSize¹::on_add_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_add_min_sizeX);
        
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_sizeX);
    }
}
