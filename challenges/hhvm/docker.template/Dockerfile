FROM hhvm/hhvm:3.30-latest
WORKDIR /app/
# Compilation
RUN useradd -ms /bin/bash hhvm
USER hhvm
COPY src /app/
RUN hhvm --hphp \
    --target hhbc \
    --output-dir "/HHVM" \
    --input-dir "/app"


EXPOSE 8080
CMD ["hhvm", "-m", "server", "-p", "8080", "-v", "Server.Type=proxygen", "-v" ,"Server.SourceRoot=/app", "-v", "Repo.Authoritative=true" , "-v", "Repo.Central.Path=/HHVM/hhvm.hhbc", "-v", "Eval.Jit=true"]

