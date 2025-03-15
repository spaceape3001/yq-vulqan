////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPositionʷ : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionʷ, PositionCommand)
    public:
        MultiplyPositionʷ(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionʷ(const MultiplyPositionʷ&, const Header&);
        MultiplyPositionʷ(const Header&);
        ~MultiplyPositionʷ();

    private:
        double  m_δw = 0.0;
        
        MultiplyPositionʷ(const MultiplyPositionʷ&) = delete;
        MultiplyPositionʷ(MultiplyPositionʷ&&) = delete;
        MultiplyPositionʷ& operator=(const MultiplyPositionʷ&) = delete;
        MultiplyPositionʷ& operator=(MultiplyPositionʷ&&) = delete;
    };
}
