import os
import glob
import json
import sys

# EXTENSIONS = {'.cpp', '.hpp'}
EXTENSIONS = {'.hpp'}
OUTPUT_FILE = 'cpp.json'


def create_snippet(file_path, at):
    name = os.path.splitext(os.path.basename(file_path))[0]
    with open(file_path, mode='r') as f:
        text = f.read()
    if(at):
        snippet = {
            'prefix': '@'+name,
            'body': text.split('\n'),
            'description': '@'+name,
        }
    else:
        snippet = {
            'prefix': name,
            'body': text.split('\n'),
            'description': name,
        }
    return snippet

def create_snippets(dir_name):
    snippets = {}
    for file_path in glob.iglob(os.path.join(dir_name+'/at/', '**', '*'), recursive=True):
        ext = os.path.splitext(file_path)[1]
        if os.path.isfile(file_path) and ext in EXTENSIONS:
            file_name = os.path.basename(file_path)
            snippets[file_name] = create_snippet(file_path, True)
    for file_path in glob.iglob(os.path.join(dir_name+'/normal/', '**', '*'), recursive=True):
        ext = os.path.splitext(file_path)[1]
        if os.path.isfile(file_path) and ext in EXTENSIONS:
            file_name = os.path.basename(file_path)
            snippets[file_name] = create_snippet(file_path, False)
    return snippets


if __name__ == '__main__':
    snippets = create_snippets(sys.argv[1])
    with open(OUTPUT_FILE, mode='w') as f:
        f.write(json.dumps(snippets, ensure_ascii=False, indent=4))