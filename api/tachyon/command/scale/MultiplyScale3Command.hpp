////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale³Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale³Command, ScaleCommand)
    public:
        MultiplyScale³Command(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScale³Command(const MultiplyScale³Command&, const Header&);
        MultiplyScale³Command(const Header&);
        ~MultiplyScale³Command();

    private:
        Vector3D  m_δ;
        
        MultiplyScale³Command(const MultiplyScale³Command&) = delete;
        MultiplyScale³Command(MultiplyScale³Command&&) = delete;
        MultiplyScale³Command& operator=(const MultiplyScale³Command&) = delete;
        MultiplyScale³Command& operator=(MultiplyScale³Command&&) = delete;
    };
}
