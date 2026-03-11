////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyPositionʸDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionʸDCommand, PositionCommand)
    public:
        MultiplyPositionʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionʸDCommand(const MultiplyPositionʸDCommand&, const Header&);
        MultiplyPositionʸDCommand(const Header&);
        ~MultiplyPositionʸDCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyPositionʸDCommand(const MultiplyPositionʸDCommand&) = delete;
        MultiplyPositionʸDCommand(MultiplyPositionʸDCommand&&) = delete;
        MultiplyPositionʸDCommand& operator=(const MultiplyPositionʸDCommand&) = delete;
        MultiplyPositionʸDCommand& operator=(MultiplyPositionʸDCommand&&) = delete;
    };
}
