////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ASize2.hpp>
#include <tachyon/command/size/AddSize2.hpp>
#include <tachyon/command/size/AddSizeX.hpp>
#include <tachyon/command/size/AddSizeY.hpp>
#include <tachyon/command/size/MultiplySize.hpp>
#include <tachyon/command/size/MultiplySize2.hpp>
#include <tachyon/command/size/MultiplySizeX.hpp>
#include <tachyon/command/size/MultiplySizeY.hpp>
#include <tachyon/command/size/SetSize2.hpp>
#include <tachyon/command/size/SetSizeX.hpp>
#include <tachyon/command/size/SetSizeY.hpp>
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
