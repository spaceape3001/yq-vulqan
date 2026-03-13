////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyScaleˣDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleˣDCommand, ScaleCommand)
    public:
        MultiplyScaleˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleˣDCommand(const MultiplyScaleˣDCommand&, const Header&);
        MultiplyScaleˣDCommand(const Header&);
        ~MultiplyScaleˣDCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyScaleˣDCommand(const MultiplyScaleˣDCommand&) = delete;
        MultiplyScaleˣDCommand(MultiplyScaleˣDCommand&&) = delete;
        MultiplyScaleˣDCommand& operator=(const MultiplyScaleˣDCommand&) = delete;
        MultiplyScaleˣDCommand& operator=(MultiplyScaleˣDCommand&&) = delete;
    };
}
