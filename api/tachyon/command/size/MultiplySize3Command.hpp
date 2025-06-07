////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplySize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize³Command, SizeCommand)
    public:
        MultiplySize³Command(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize³Command(const MultiplySize³Command&, const Header&);
        MultiplySize³Command(const Header&);
        ~MultiplySize³Command();

    private:
        Vector3D  m_δ;
        
        MultiplySize³Command(const MultiplySize³Command&) = delete;
        MultiplySize³Command(MultiplySize³Command&&) = delete;
        MultiplySize³Command& operator=(const MultiplySize³Command&) = delete;
        MultiplySize³Command& operator=(MultiplySize³Command&&) = delete;
    };
}
