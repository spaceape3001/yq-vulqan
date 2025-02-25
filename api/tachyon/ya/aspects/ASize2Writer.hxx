////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize2.hpp>
#include <ya/commands/size/AddSize2.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/AddSizeY.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize2.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/MultiplySizeY.hpp>
#include <ya/commands/size/SetSize2.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <ya/commands/size/SetSizeY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ISize²>();
        w.property(UNSAFE, "size", &ASize²::m_size).tag(kTag_Save);

        w.slot(UNSAFE, &ASize²::on_set_size2);
        w.slot(UNSAFE, &ASize²::on_set_sizeX);
        w.slot(UNSAFE, &ASize²::on_set_sizeY);

        w.slot(UNSAFE, &ASize²::on_add_size2);
        w.slot(UNSAFE, &ASize²::on_add_sizeX);
        w.slot(UNSAFE, &ASize²::on_add_sizeY);
        
        w.slot(UNSAFE, &ASize²::on_multiply_size);
        w.slot(UNSAFE, &ASize²::on_multiply_size2);
        w.slot(UNSAFE, &ASize²::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize²::on_multiply_sizeY);
    }
}
