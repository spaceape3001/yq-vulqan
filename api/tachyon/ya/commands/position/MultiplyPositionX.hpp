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
    class MultiplyPositionˣ : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionˣ, PositionCommand)
    public:
        MultiplyPositionˣ(const Header&, double);
        
        static void init_info();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionˣ(const MultiplyPositionˣ&, const Header&);
        MultiplyPositionˣ(const Header&);
        ~MultiplyPositionˣ();

    private:
        double  m_δx = 0.0;
        
        MultiplyPositionˣ(const MultiplyPositionˣ&) = delete;
        MultiplyPositionˣ(MultiplyPositionˣ&&) = delete;
        MultiplyPositionˣ& operator=(const MultiplyPositionˣ&) = delete;
        MultiplyPositionˣ& operator=(MultiplyPositionˣ&&) = delete;
    };
}
