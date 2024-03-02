import os
try:
    import git
except:
    os.system("pip install GitPython")
    import git
import os

def update_from_git():
    repository_url = "https://github.com/HeisenbergCipherCracker/sqlgo.git"
    local_path = os.getcwd()

    try:
        repo = git.Repo(local_path)
    except git.NoSuchPathError:
        repo = git.Repo.clone_from(repository_url, local_path)

    repo.remotes.origin.fetch()

    repo.head.reset(index=True, working_tree=True)

    repo.remotes.origin.pull()

