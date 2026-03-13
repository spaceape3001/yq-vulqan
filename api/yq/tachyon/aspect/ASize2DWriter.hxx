////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ASize2D.hpp>
#include <yq/tachyon/command/size/AddSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize²D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize²D>();
        w.property(UNSAFE, "size", &ASize²D::m_size).def_value(kDefSize).tag(kTag_Save);

        w.slot(UNSAFE, &ASize²D::on_set_size2);
        w.slot(UNSAFE, &ASize²D::on_set_sizeX);
        w.slot(UNSAFE, &ASize²D::on_set_sizeY);

        w.slot(UNSAFE, &ASize²D::on_add_size2);
        w.slot(UNSAFE, &ASize²D::on_add_sizeX);
        w.slot(UNSAFE, &ASize²D::on_add_sizeY);
        
        w.slot(UNSAFE, &ASize²D::on_multiply_size);
        w.slot(UNSAFE, &ASize²D::on_multiply_size2);
        w.slot(UNSAFE, &ASize²D::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize²D::on_multiply_sizeY);
    }
}
