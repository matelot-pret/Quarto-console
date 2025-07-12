# Instructions pour pousser le projet sur GitHub

## 1. Créer le repository sur GitHub
- Allez sur github.com
- Cliquez sur "New repository"
- Nom suggéré: "quarto-game" ou "jeu-quarto"
- Description: "Implémentation du jeu de Quarto en C - Projet de Méthodes de Programmation"
- Public ou Private selon votre choix
- NE PAS cocher "Add a README file" ou "Add .gitignore"

## 2. Connecter le repository local à GitHub
Remplacez VOTRE-USERNAME et NOM-DU-REPO par vos vraies valeurs :

### Option A: HTTPS (recommandé pour débuter)
```bash
git remote add origin https://github.com/VOTRE-USERNAME/NOM-DU-REPO.git
git branch -M main
git push -u origin main
```

### Option B: SSH (si vous avez configuré les clés SSH)
```bash
git remote add origin git@github.com:VOTRE-USERNAME/NOM-DU-REPO.git
git branch -M main
git push -u origin main
```

## 3. Vérifier la connexion
```bash
git remote -v
```

## 4. Pour les futurs commits
Après avoir fait des modifications :
```bash
git add .
git commit -m "Votre message de commit"
git push
```

## 5. Exemple concret
Si votre username GitHub est "matelot-pret" et votre repo s'appelle "quarto-game":
```bash
git remote add origin https://github.com/matelot-pret/quarto-game.git
git branch -M main
git push -u origin main
```
