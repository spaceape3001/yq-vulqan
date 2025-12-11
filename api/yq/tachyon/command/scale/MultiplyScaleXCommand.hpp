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
    class MultiplyScaleˣCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleˣCommand, ScaleCommand)
    public:
        MultiplyScaleˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleˣCommand(const MultiplyScaleˣCommand&, const Header&);
        MultiplyScaleˣCommand(const Header&);
        ~MultiplyScaleˣCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyScaleˣCommand(const MultiplyScaleˣCommand&) = delete;
        MultiplyScaleˣCommand(MultiplyScaleˣCommand&&) = delete;
        MultiplyScaleˣCommand& operator=(const MultiplyScaleˣCommand&) = delete;
        MultiplyScaleˣCommand& operator=(MultiplyScaleˣCommand&&) = delete;
    };
}
