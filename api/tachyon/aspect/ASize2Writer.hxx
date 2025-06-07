////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ASize2.hpp>
#include <tachyon/command/size/AddSize2Command.hpp>
#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/command/size/AddSizeYCommand.hpp>
#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/command/size/MultiplySize2Command.hpp>
#include <tachyon/command/size/MultiplySizeXCommand.hpp>
#include <tachyon/command/size/MultiplySizeYCommand.hpp>
#include <tachyon/command/size/SetSize2Command.hpp>
#include <tachyon/command/size/SetSizeXCommand.hpp>
#include <tachyon/command/size/SetSizeYCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

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
