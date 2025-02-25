////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize1.hpp>
#include <ya/commands/size/AddSize1.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize1.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/SetSize1.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ISize¹>();
        w.property(UNSAFE, "size", &ASize¹::m_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &ASize¹::on_set_size1);
        w.slot(UNSAFE, &ASize¹::on_set_sizeX);

        w.slot(UNSAFE, &ASize¹::on_add_size1);
        w.slot(UNSAFE, &ASize¹::on_add_sizeX);
        
        w.slot(UNSAFE, &ASize¹::on_multiply_size);
        w.slot(UNSAFE, &ASize¹::on_multiply_size1);
        w.slot(UNSAFE, &ASize¹::on_multiply_sizeX);
    }
}
