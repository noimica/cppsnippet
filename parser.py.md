---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\r\nimport glob\r\nimport json\r\nimport sys\r\n\r\n# EXTENSIONS\
    \ = {'.cpp', '.hpp'}\r\nEXTENSIONS = {'.hpp'}\r\nOUTPUT_FILE = 'cpp.json'\r\n\r\
    \n\r\ndef create_snippet(file_path, at):\r\n    name = os.path.splitext(os.path.basename(file_path))[0]\r\
    \n    with open(file_path, mode='r') as f:\r\n        text = f.read()\r\n    if(at):\r\
    \n        snippet = {\r\n            'prefix': '@'+name,\r\n            'body':\
    \ text.split('\\n'),\r\n            'description': '@'+name,\r\n        }\r\n\
    \    else:\r\n        snippet = {\r\n            'prefix': name,\r\n         \
    \   'body': text.split('\\n'),\r\n            'description': name,\r\n       \
    \ }\r\n    return snippet\r\n\r\ndef create_snippets(dir_name):\r\n    snippets\
    \ = {}\r\n    for file_path in glob.iglob(os.path.join(dir_name+'/at/', '**',\
    \ '*'), recursive=True):\r\n        ext = os.path.splitext(file_path)[1]\r\n \
    \       if os.path.isfile(file_path) and ext in EXTENSIONS:\r\n            file_name\
    \ = os.path.basename(file_path)\r\n            snippets[file_name] = create_snippet(file_path,\
    \ True)\r\n    for file_path in glob.iglob(os.path.join(dir_name+'/normal/', '**',\
    \ '*'), recursive=True):\r\n        ext = os.path.splitext(file_path)[1]\r\n \
    \       if os.path.isfile(file_path) and ext in EXTENSIONS:\r\n            file_name\
    \ = os.path.basename(file_path)\r\n            snippets[file_name] = create_snippet(file_path,\
    \ False)\r\n    return snippets\r\n\r\n\r\nif __name__ == '__main__':\r\n    snippets\
    \ = create_snippets(sys.argv[1])\r\n    with open(OUTPUT_FILE, mode='w') as f:\r\
    \n        f.write(json.dumps(snippets, ensure_ascii=False, indent=4))"
  dependsOn: []
  isVerificationFile: false
  path: parser.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: parser.py
layout: document
redirect_from:
- /library/parser.py
- /library/parser.py.html
title: parser.py
---
