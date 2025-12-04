#! Saving

## Use Cases

### Snapshot

This is a full save of all attributes, elements, etc; no shortcuts.

### Save

A save of all pertinent attributes, elements.  Game save would likely be here, to avoid resaving out pre-baked assets.  (ie... we don't need to put the door's location into the save file, only its current open/close state along to a reference to the door's instance).

### Game Level

A construct of a game level or similar asset.  

### Templates

Snippets meant for reuse.  Examples:
* Throne with mesh, collision, materials, lighting, attachment points, plumbing, sound effects, state, etc
* Delegates with configuration
* A car, a wall segment, etc

## Concepts

"Save" is the unit that goes to the file... collection of smaller saves. 


"Builder" is the thing that makes things. ... can be a delegate builder, tachyon builder, object builder, post builder, etc

"Description" or "Definition" or "Recipe" ...?  

"LibraryFile" ... collection of templates (right now, that'd be a directory...)

"Template" is the more generic description (or components?)

