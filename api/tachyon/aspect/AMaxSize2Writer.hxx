////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMaxSize2.hpp>
#include <tachyon/command/size/AddMaxSize2Command.hpp>
#include <tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSize2Command.hpp>
#include <tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <tachyon/command/size/SetMaxSize2Command.hpp>
#include <tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize²::init_meta(TachyonMeta::Writer<C>&w)
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
