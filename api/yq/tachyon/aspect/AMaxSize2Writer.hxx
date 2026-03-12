////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMaxSize2.hpp>
#include <yq/tachyon/command/size/AddMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

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
