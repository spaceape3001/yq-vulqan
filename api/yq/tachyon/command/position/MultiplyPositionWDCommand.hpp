////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPositionʷDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionʷDCommand, PositionCommand)
    public:
        MultiplyPositionʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionʷDCommand(const MultiplyPositionʷDCommand&, const Header&);
        MultiplyPositionʷDCommand(const Header&);
        ~MultiplyPositionʷDCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyPositionʷDCommand(const MultiplyPositionʷDCommand&) = delete;
        MultiplyPositionʷDCommand(MultiplyPositionʷDCommand&&) = delete;
        MultiplyPositionʷDCommand& operator=(const MultiplyPositionʷDCommand&) = delete;
        MultiplyPositionʷDCommand& operator=(MultiplyPositionʷDCommand&&) = delete;
    };
}
