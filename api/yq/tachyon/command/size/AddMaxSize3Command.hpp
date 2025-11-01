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
    class AddMaxSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize³Command, SizeCommand)
    public:
        AddMaxSize³Command(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize³Command(const AddMaxSize³Command&, const Header&);
        AddMaxSize³Command(const Header&);
        ~AddMaxSize³Command();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddMaxSize³Command(const AddMaxSize³Command&) = delete;
        AddMaxSize³Command(AddMaxSize³Command&&) = delete;
        AddMaxSize³Command& operator=(const AddMaxSize³Command&) = delete;
        AddMaxSize³Command& operator=(AddMaxSize³Command&&) = delete;
    };
}
