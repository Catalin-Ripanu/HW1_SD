build: editor

editor: editor.c
	gcc editor.c -o editor
	
	
clean:
	rm editor
	
