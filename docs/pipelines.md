#! Pipelines

Pipeline "Role" is about different pipeline layouts.

Pipeline "Variations" is about light tweaks to the pipeline (ie reversing the face orientation, and/or mainly the shaders).

## Roles

The pipeline role is a completely different pipeline layout, nothing is shared between pipelines (though pipelines might share shaders, buffer definitions, etc, though these must be explicitly stated and repeated).

    auto w = writer<MyRendered>();
    {
        auto& p = w.pipeline();
        p.shader( ... );
        p.vertex( ... );
    }
    {
        auto& psc = w.pipeline(Pipeline::Role::SolidColor);
        p.shader( ... );
        p.vertex( ... );
    }

## Variations

Variation is a tweak to the same pipeline layout. 

    auto w = writer<MyRendered>();
    auto& p = w.pipeline();
    
