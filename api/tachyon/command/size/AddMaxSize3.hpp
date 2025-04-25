////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize³ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize³, SizeCommand)
    public:
        AddMaxSize³(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize³(const AddMaxSize³&, const Header&);
        AddMaxSize³(const Header&);
        ~AddMaxSize³();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddMaxSize³(const AddMaxSize³&) = delete;
        AddMaxSize³(AddMaxSize³&&) = delete;
        AddMaxSize³& operator=(const AddMaxSize³&) = delete;
        AddMaxSize³& operator=(AddMaxSize³&&) = delete;
    };
}
